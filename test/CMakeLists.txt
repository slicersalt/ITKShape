itk_module_test()

set(Mesh3DProcrustesAlignFilterTests
  itkMeshProcrustesAlignFilterTest.cxx
  )

CreateTestDriver(Mesh3DProcrustesAlignFilter "${Mesh3DProcrustesAlignFilter-Test_LIBRARIES}" "${Mesh3DProcrustesAlignFilterTests}")

itk_add_test(NAME itkMeshProcrustesAlignFilterTest
  COMMAND Mesh3DProcrustesAlignFilterTestDriver itkMeshProcrustesAlignFilterTest
  )
