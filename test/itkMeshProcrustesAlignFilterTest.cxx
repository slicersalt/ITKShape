/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         https://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/
#include <iostream>

#include "itkMesh.h"
#include "itkMeshFileReader.h"
#include "itkMeshFileWriter.h"
#include "itkMeshProcrustesAlignFilter.h"

int itkMeshProcrustesAlignFilterTest(int argc, char* argv[])
{
    if (argc < 4) {
        std::cout << "Usage: MeshProcrustesAlignFilterTest <input1.vtk> <input2.vtk> <output.vtk>" << std::endl;
        return EXIT_FAILURE;
    }

    const int Dimension = 3;
    using CoordRepType = double;
    using MeshType = itk::Mesh<CoordRepType, Dimension>;
    
    // Read in meshes
    using ReaderType = itk::MeshFileReader<MeshType>;
    ReaderType::Pointer meshReader1 = ReaderType::New();
    meshReader1->SetFileName(argv[1]);
    meshReader1->Update();

    ReaderType::Pointer meshReader2 = ReaderType::New();
    meshReader2->SetFileName(argv[2]);
    meshReader2->Update();

    // Get mean mesh
    using FilterType = itk::MeshProcrustesAlignFilter<MeshType, MeshType>;
    FilterType::Pointer filter = FilterType::New();
    FilterType::InputMeshType::Pointer mesh1 = meshReader1->GetOutput();
    FilterType::InputMeshType::Pointer mesh2 = meshReader2->GetOutput();
    filter->SetNumberOfInputs(2);
    filter->SetInput(0, mesh1);
    filter->SetInput(1, mesh2);

    // Set application-specific parameters
    filter->SetConvergence(50.0);
    filter->SetUseInitialAverageOff();
    filter->SetUseNormalizationOff();
    filter->SetUseScalingOff();

    // Run a single iteration to show that registration executes
    filter->SetUseSingleIterationOn();
    filter->Update();

    // Write out mean mesh result
    using WriterType = itk::MeshFileWriter<MeshType>;
    WriterType::Pointer meshWriter = WriterType::New();
    meshWriter->SetFileName(argv[3]);
    meshWriter->SetInput(filter->GetMean());
    meshWriter->Update();

    return EXIT_SUCCESS;
}
