file(REMOVE_RECURSE
  "lib/libopenvml.pdb"
  "lib/libopenvml.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang C)
  include(CMakeFiles/openvml_static.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
