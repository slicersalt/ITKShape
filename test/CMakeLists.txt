itk_module_test()

set(Mesh3DProcrustesAlignFilterTests
  itkMeshProcrustesAlignFilterTest.cxx
  )

CreateTestDriver(Mesh3DProcrustesAlignFilter "${Mesh3DProcrustesAlignFilter-Test_LIBRARIES}" "${Mesh3DProcrustesAlignFilterTests}")

itk_add_test(NAME itkMeshProcrustesAlignFilterTest
  COMMAND Mesh3DProcrustesAlignFilterTestDriver itkMeshProcrustesAlignFilterTest
	DATA{Input/901-L-mesh.vtk}
	DATA{Input/901-R-mesh.vtk}
    "${CMAKE_CURRENT_BINARY_DIR}/Output.vtk"
  )
