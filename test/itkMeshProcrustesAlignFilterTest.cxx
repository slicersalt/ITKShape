/*=========================================================================
 *
 *  Copyright NumFOCUS
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#include "itkMeshProcrustesAlignFilter.h"

int itkMeshProcrustesAlignFilterTest(int argc, char* argv[])
{
    using MeshType = itk::Mesh<double, 3>;
    using FilterType = itk::MeshProcrustesAlignFilter<MeshType, MeshType>;

    FilterType::Pointer filter = FilterType::New();

    // Empty test to verify build success
    return EXIT_SUCCESS;
}
