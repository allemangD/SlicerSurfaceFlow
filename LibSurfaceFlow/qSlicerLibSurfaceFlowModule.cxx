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

// LibSurfaceFlow Logic includes
#include <vtkSlicerLibSurfaceFlowLogic.h>

// LibSurfaceFlow includes
#include "qSlicerLibSurfaceFlowModule.h"
#include "qSlicerLibSurfaceFlowModuleWidget.h"

//-----------------------------------------------------------------------------
class qSlicerLibSurfaceFlowModulePrivate
{
public:
  qSlicerLibSurfaceFlowModulePrivate();
};

//-----------------------------------------------------------------------------
// qSlicerLibSurfaceFlowModulePrivate methods

//-----------------------------------------------------------------------------
qSlicerLibSurfaceFlowModulePrivate::qSlicerLibSurfaceFlowModulePrivate()
{
}

//-----------------------------------------------------------------------------
// qSlicerLibSurfaceFlowModule methods

//-----------------------------------------------------------------------------
qSlicerLibSurfaceFlowModule::qSlicerLibSurfaceFlowModule(QObject* _parent)
  : Superclass(_parent)
  , d_ptr(new qSlicerLibSurfaceFlowModulePrivate)
{
}

//-----------------------------------------------------------------------------
qSlicerLibSurfaceFlowModule::~qSlicerLibSurfaceFlowModule()
{
}

//-----------------------------------------------------------------------------
QString qSlicerLibSurfaceFlowModule::helpText() const
{
  return "This is a loadable module that can be bundled in an extension";
}

//-----------------------------------------------------------------------------
QString qSlicerLibSurfaceFlowModule::acknowledgementText() const
{
  return "This work was partially funded by NIH grant NXNNXXNNNNNN-NNXN";
}

//-----------------------------------------------------------------------------
QStringList qSlicerLibSurfaceFlowModule::contributors() const
{
  QStringList moduleContributors;
  moduleContributors << QString("John Doe (AnyWare Corp.)");
  return moduleContributors;
}

//-----------------------------------------------------------------------------
QIcon qSlicerLibSurfaceFlowModule::icon() const
{
  return QIcon(":/Icons/LibSurfaceFlow.png");
}

//-----------------------------------------------------------------------------
QStringList qSlicerLibSurfaceFlowModule::categories() const
{
  return QStringList() << "Examples";
}

//-----------------------------------------------------------------------------
QStringList qSlicerLibSurfaceFlowModule::dependencies() const
{
  return QStringList();
}

//-----------------------------------------------------------------------------
void qSlicerLibSurfaceFlowModule::setup()
{
  this->Superclass::setup();
}

//-----------------------------------------------------------------------------
qSlicerAbstractModuleRepresentation* qSlicerLibSurfaceFlowModule
::createWidgetRepresentation()
{
  return new qSlicerLibSurfaceFlowModuleWidget;
}

//-----------------------------------------------------------------------------
vtkMRMLAbstractLogic* qSlicerLibSurfaceFlowModule::createLogic()
{
  return vtkSlicerLibSurfaceFlowLogic::New();
}
