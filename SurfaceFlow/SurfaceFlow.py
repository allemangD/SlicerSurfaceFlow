from __future__ import annotations

import logging
from typing import TYPE_CHECKING

import slicer
from MRMLCorePython import vtkMRMLScene
from slicer.i18n import tr as _
from slicer.ScriptedLoadableModule import *
from slicer.util import VTKObservationMixin
from slicer.parameterNodeWrapper import (
    parameterNodeWrapper,
)
from slicer import vtkMRMLScalarVolumeNode
from vtkmodules.vtkCommonCore import vtkCommand

if TYPE_CHECKING:
    from PyQt5.QtWidgets import QWidget

    qMRMLNodeComboBox = QWidget

    class vtkSlicerLibSurfaceFlowLogic:
        def DoSomething(self) -> None: ...


class SurfaceFlow(ScriptedLoadableModule):
    def __init__(self, parent):
        ScriptedLoadableModule.__init__(self, parent)
        self.parent.title = _("Surface Flow")
        self.parent.categories = [_("Surface Flow")]
        self.parent.dependencies = []
        self.parent.contributors = ["David Allemang (University of North Carolina at Chapel Hill)"]
        self.parent.helpText = _("Provides Slicer integration and analysis of surface flows.")
        self.parent.acknowledgementText = _(
            "This work is done as a course project for COMP 766 with Dr. Steve Pizer."
        )


@parameterNodeWrapper
class SurfaceFlowParams:
    pass


class UI:
    inputSelector: qMRMLNodeComboBox


class SurfaceFlowWidget(ScriptedLoadableModuleWidget, VTKObservationMixin):
    ui: UI
    logic: SurfaceFlowLogic
    _params: SurfaceFlowParams

    def __init__(self, parent=None) -> None:
        ScriptedLoadableModuleWidget.__init__(self, parent)
        VTKObservationMixin.__init__(self)  # needed for parameter node observation

        self.logger = logging.getLogger("SurfaceFlow.Widget")

    def setup(self) -> None:
        self.logger.debug("setup")

        ScriptedLoadableModuleWidget.setup(self)

        ui = slicer.util.loadUI(self.resourcePath("UI/SurfaceFlow.ui"))
        self.layout.addWidget(ui)

        self.ui = UI()
        self.ui.__dict__ = {
            widget.name: widget for widget in slicer.util.findChildren(ui) if getattr(widget, "name", None)
        }

        ui.setMRMLScene(slicer.mrmlScene)

        self.logic = SurfaceFlowLogic()

        # Connections
        self.addObserver(
            slicer.mrmlScene,
            vtkMRMLScene.StartBatchProcessEvent,
            self.onStartBatchProcess,
        )
        self.addObserver(slicer.mrmlScene, vtkMRMLScene.EndBatchProcessEvent, self.onEndBatchProcess)

    def cleanup(self) -> None:
        """Called when the application closes and the module widget is destroyed."""
        self.logger.debug("cleanup")

    def enter(self) -> None:
        self.logger.debug("enter")
        self._params = self.logic.getParameterNode()
        self.addObserver(self._params, vtkCommand.ModifiedEvent, self.onParamsModified)
        self._params.Modified()

    def exit(self) -> None:
        self.logger.debug("exit")
        if self.hasObserver(self._params, vtkCommand.ModifiedEvent, self.onParamsModified):
            self.removeObserver(self._params, vtkCommand.ModifiedEvent, self.onParamsModified)

    def onStartBatchProcess(self, o, e):
        self.logger.debug("onStartBatchProcess")
        if self.parent.isEntered:
            self.exit()

    def onEndBatchProcess(self, o, e):
        self.logger.debug("onEndBatchProcess")
        if self.parent.isEntered:
            self.enter()

    def onParamsModified(self, o, e):
        self.logger.debug("onParamsModified")


class SurfaceFlowLogic(ScriptedLoadableModuleLogic, VTKObservationMixin):
    def __init__(self, parent=None) -> None:
        ScriptedLoadableModuleLogic.__init__(self, parent)
        VTKObservationMixin.__init__(self)

        self.logger = logging.getLogger("SurfaceFlow.Logic")

        self.liblogic: vtkSlicerLibSurfaceFlowLogic = slicer.modules.libsurfaceflow.logic()
        self.instance: SurfaceFlow = slicer.modules.SurfaceFlowInstance

    def getParameterNode(self) -> SurfaceFlowParams:
        return SurfaceFlowParams(super().getParameterNode())


class SurfaceFlowTest(ScriptedLoadableModuleTest):
    def setUp(self):
        slicer.mrmlScene.Clear()

    def runTest(self):
        self.setUp()
