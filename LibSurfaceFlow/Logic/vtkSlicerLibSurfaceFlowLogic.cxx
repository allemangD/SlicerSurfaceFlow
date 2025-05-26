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

#include "vtkSlicerLibSurfaceFlowLogic.h"

#include <qlogging.h>
#include <vtkMRMLScene.h>
#include <vtkIntArray.h>
#include <vtkNew.h>
#include <vtkObjectFactory.h>

#include <cassert>

#include <Eigen/Eigen>
#include <igl/cotmatrix.h>

vtkStandardNewMacro(vtkSlicerLibSurfaceFlowLogic);

vtkSlicerLibSurfaceFlowLogic::vtkSlicerLibSurfaceFlowLogic() = default;

vtkSlicerLibSurfaceFlowLogic::~vtkSlicerLibSurfaceFlowLogic() = default;

void vtkSlicerLibSurfaceFlowLogic::PrintSelf(ostream& os, vtkIndent indent) {
  this->Superclass::PrintSelf(os, indent);
}

void vtkSlicerLibSurfaceFlowLogic::DoSomething() {
  qInfo("Hello World!");
}

void vtkSlicerLibSurfaceFlowLogic::SetMRMLSceneInternal(vtkMRMLScene* newScene) {
  vtkNew<vtkIntArray> events;
  events->InsertNextValue(vtkMRMLScene::NodeAddedEvent);
  events->InsertNextValue(vtkMRMLScene::NodeRemovedEvent);
  events->InsertNextValue(vtkMRMLScene::EndBatchProcessEvent);
  this->SetAndObserveMRMLSceneEventsInternal(newScene, events.GetPointer());
}

void vtkSlicerLibSurfaceFlowLogic::RegisterNodes() {
  assert(this->GetMRMLScene() != 0);
}

void vtkSlicerLibSurfaceFlowLogic::UpdateFromMRMLScene() {
  assert(this->GetMRMLScene() != 0);
}

void vtkSlicerLibSurfaceFlowLogic::OnMRMLSceneNodeAdded(vtkMRMLNode* vtkNotUsed(node)) {}

void vtkSlicerLibSurfaceFlowLogic::OnMRMLSceneNodeRemoved(vtkMRMLNode* vtkNotUsed(node)) {}