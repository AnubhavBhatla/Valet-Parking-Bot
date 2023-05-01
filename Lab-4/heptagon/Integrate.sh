#!/usr/bin/bash
heptc -target c Logic.ept
cp logic_c/* supervisor
pushd supervisor > /dev/null
sed --in-place '/pervasives.h/d' logic_types.h
echo "extern \"C\" {" > logic.hpp
cat logic.h >> logic.hpp
echo "}" >> logic.hpp
popd > /dev/null
rm -rf logic_c logic.epci logic.log logic.mls
