itk_module_test()

set(Mesh3DProcrustesAlignFilterTests
  itkMinimalStandardRandomVariateGeneratorTest.cxx
  itkMyFilterTest.cxx
  )

CreateTestDriver(Mesh3DProcrustesAlignFilter "${Mesh3DProcrustesAlignFilter-Test_LIBRARIES}" "${Mesh3DProcrustesAlignFilterTests}")

itk_add_test(NAME itkMinimalStandardRandomVariateGeneratorTest
  COMMAND Mesh3DProcrustesAlignFilterTestDriver itkMinimalStandardRandomVariateGeneratorTest
  )

itk_add_test(NAME itkMyFilterTest
  COMMAND Mesh3DProcrustesAlignFilterTestDriver
    --compare
    DATA{Baseline/itkMyFilterTestOutput.mha}
    ${ITK_TEST_OUTPUT_DIR}/itkMyFilterTestOutput.mha
  itkMyFilterTest
    ${ITK_TEST_OUTPUT_DIR}/itkMyFilterTestOutput.mha
  )
