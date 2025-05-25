/*==============================================================================

  Program: 3D Slicer

  Portions (c) Copyright Brigham and Women's Hospital (BWH) All Rights Reserved.

  See COPYRIGHT.txt
  or http://www.slicer.org/copyright/copyright.txt for details.

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

==============================================================================*/
#pragma once

// Slicer includes
#include "qSlicerLoadableModule.h"

#include "qSlicerLibSurfaceFlowModuleExport.h"

class qSlicerLibSurfaceFlowModulePrivate;

class Q_SLICER_QTMODULES_LIBSURFACEFLOW_EXPORT
    qSlicerLibSurfaceFlowModule
    : public qSlicerLoadableModule {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.slicer.modules.loadable.qSlicerLoadableModule/1.0");
  Q_INTERFACES(qSlicerLoadableModule);

public:
  typedef qSlicerLoadableModule Superclass;
  explicit qSlicerLibSurfaceFlowModule(QObject* parent = nullptr);
  ~qSlicerLibSurfaceFlowModule() override;

  [[nodiscard]] bool isHidden() const override;

  qSlicerGetTitleMacro(tr("LibSurfaceFlow"));

  [[nodiscard]] QString helpText() const override;
  [[nodiscard]] QString acknowledgementText() const override;
  [[nodiscard]] QStringList contributors() const override;

  [[nodiscard]] QIcon icon() const override;

  [[nodiscard]] QStringList categories() const override;
  [[nodiscard]] QStringList dependencies() const override;

protected:
  /// Initialize the module. Register the volumes reader/writer
  void setup() override;

  /// Create and return the widget representation associated to this module
  qSlicerAbstractModuleRepresentation* createWidgetRepresentation() override;

  /// Create and return the logic associated to this module
  vtkMRMLAbstractLogic* createLogic() override;

protected:
  QScopedPointer<qSlicerLibSurfaceFlowModulePrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(qSlicerLibSurfaceFlowModule);
  Q_DISABLE_COPY(qSlicerLibSurfaceFlowModule);
};