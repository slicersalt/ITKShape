itk_module_test()

set(ShapeTests
  itkMeshProcrustesAlignFilterTest.cxx
  )

CreateTestDriver(Shape "${Shape-Test_LIBRARIES}" "${ShapeTests}")

itk_add_test(NAME itkMeshProcrustesAlignFilterTest
  COMMAND ShapeTestDriver itkMeshProcrustesAlignFilterTest
	DATA{Input/901-L-mesh.vtk}
	DATA{Input/901-R-mesh.vtk}
    "${CMAKE_CURRENT_BINARY_DIR}/Output.vtk"
  )
