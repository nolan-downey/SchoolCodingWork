echo "Running with no following inputs: ./tempSpec"
./tempSpec
echo ""
echo "Run Bad Type: ./tempSpec badTypeName 22 44 57 99"
./tempSpec badTypeName 22 44 57 99
echo ""
echo "Run int but no following inputs: ./tempSpec int"
./tempSpec int
echo ""
echo "Run an int test: ./tempSpec int 10 13 -5 -1 27"
./tempSpec int 10 13 -5 -1 27
echo ""
echo "Run a double test: ./tempSpec double 3.2 7.22 -22.85 10.22"
./tempSpec double 3.2 7.22 -22.85 10.22
echo ""
echo "Run a float test: ./tempSpec float 3.2 7.22 -22.85 10.22"
./tempSpec float 3.2 7.22 -22.85 10.22
echo ""
echo "Run a string test: ./tempSpec std::string Notre Dame Fighting Irish"
./tempSpec std::string Notre Dame Fighting Irish