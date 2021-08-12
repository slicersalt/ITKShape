itk_module_test()

set(ITKShapeTests
  itkMeshProcrustesAlignFilterTest.cxx
  )

CreateTestDriver(ITKShape "${ITKShape-Test_LIBRARIES}" "${ITKShapeTests}")

itk_add_test(NAME itkMeshProcrustesAlignFilterTest
  COMMAND ITKShapeTestDriver itkMeshProcrustesAlignFilterTest
	DATA{Input/901-L-mesh.vtk}
	DATA{Input/901-R-mesh.vtk}
    "${CMAKE_CURRENT_BINARY_DIR}/Output.vtk"
  )
