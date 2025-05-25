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

#include <vtkSlicerLibSurfaceFlowLogic.h>

#include "qSlicerLibSurfaceFlowModule.h"

class qSlicerLibSurfaceFlowModulePrivate {
public:
  qSlicerLibSurfaceFlowModulePrivate();
};

qSlicerLibSurfaceFlowModulePrivate::qSlicerLibSurfaceFlowModulePrivate() = default;

qSlicerLibSurfaceFlowModule::qSlicerLibSurfaceFlowModule(QObject* _parent)
  : Superclass(_parent)
    , d_ptr(new qSlicerLibSurfaceFlowModulePrivate) {
  setWidgetRepresentationCreationEnabled(false);
}

qSlicerLibSurfaceFlowModule::~qSlicerLibSurfaceFlowModule() = default;

bool qSlicerLibSurfaceFlowModule::isHidden() const {
  return true;
}

QString qSlicerLibSurfaceFlowModule::helpText() const {
  return "Provides C++ implementations of surface flows.";
}

QString qSlicerLibSurfaceFlowModule::acknowledgementText() const {
  return "This work is done as a course project for COMP 766 with Dr. Steve Pizer.";
}

QStringList qSlicerLibSurfaceFlowModule::contributors() const {
  QStringList moduleContributors;
  moduleContributors << QString("David Allemang (University of North Carolina at Chapel Hill)");
  return moduleContributors;
}

QIcon qSlicerLibSurfaceFlowModule::icon() const {
  return QIcon(":/Icons/LibSurfaceFlow.png");
}

QStringList qSlicerLibSurfaceFlowModule::categories() const {
  return {"Surface Flow"};
}

QStringList qSlicerLibSurfaceFlowModule::dependencies() const {
  return {};
}

void qSlicerLibSurfaceFlowModule::setup() { this->Superclass::setup(); }

qSlicerAbstractModuleRepresentation* qSlicerLibSurfaceFlowModule
::createWidgetRepresentation() {
  return nullptr;
}

vtkMRMLAbstractLogic* qSlicerLibSurfaceFlowModule::createLogic() {
  return vtkSlicerLibSurfaceFlowLogic::New();
}