itk_python_expression_add_test(NAME itkMeshProcrustesAlignFilterD2PythonTest
  EXPRESSION "instance = itk.MeshProcrustesAlignFilter[itk.Mesh[itk.D,2],itk.Mesh[itk.D,2]].New()")
itk_python_expression_add_test(NAME itkMeshProcrustesAlignFilterD3PythonTest
  EXPRESSION "instance = itk.MeshProcrustesAlignFilter[itk.Mesh[itk.D,3],itk.Mesh[itk.D,3]].New()")