file(REMOVE_RECURSE
  "runAllTests.pdb"
  "runAllTests"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/runAllTests.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
