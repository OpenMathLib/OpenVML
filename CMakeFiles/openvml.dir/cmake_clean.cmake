file(REMOVE_RECURSE
  "lib/libopenvml.pdb"
  "lib/libopenvml.so"
  "lib/libopenvml.so.0.0"
  "lib/libopenvml.so.0"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/openvml.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
