itk_module_test()

set(Mesh3DProcrustesAlignFilterTests
  itkMesh3DProcrustesAlignFilterTest.cxx
  )

CreateTestDriver(Mesh3DProcrustesAlignFilter "${Mesh3DProcrustesAlignFilter-Test_LIBRARIES}" "${Mesh3DProcrustesAlignFilterTests}")

itk_add_test(NAME itkMesh3DProcrustesAlignFilterTest
  COMMAND Mesh3DProcrustesAlignFilterTestDriver itkMesh3DProcrustesAlignFilterTest
  )
