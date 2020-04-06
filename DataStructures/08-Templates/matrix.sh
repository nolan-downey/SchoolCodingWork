echo "Running with no following inputs: ./matrix"
./matrix
echo ""
echo "Run Bad Type: ./matrix badTypeName 22 44 57 99"
./matrix badTypeName 22 44 57 99
echo ""
echo "Run int but no following inputs: ./matrix int"
./matrix int
echo ""
echo "Run int with a 2, but no following inputs: ./matrix int 2"
./matrix int 2
echo ""
echo "Run int with a 2, but not enough inputs: ./matrix int 2 1 3 4"
./matrix int 2 1 3 4
echo ""
echo "Run int with a 2, but too many inputs: ./matrix int 2 1 3 4 7 5"
./matrix int 2 1 3 4 7 5
echo ""
echo "Run a valid double test: ./matrix double 2 10 13 -5 -1"
./matrix double 2 1 2 3 4
echo ""
echo "Run a valid int test: ./matrix int 2 10 13 -5 -1"
./matrix int 2 10 13 -5 -1
echo ""
echo "Run a valid double test: ./matrix double 3 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0"
./matrix double 3 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0
echo ""
echo "Run a valid float test: ./matrix float 3 3.1 6.2 -5.1 -1.4 7.7 -8.9 100 44.6"
./matrix float 3 3.1 6.2 -5.1 -1.4 7.7 -8.9 100 44.6 1842
echo ""
echo "Run a valid int test: ./matrix int 4 2 4 1 -3 7 2 2 -2 3 3 2 2 0 5 1 0"
./matrix float 4 2 4 1 -3 7 2 2 -2 3 3 2 2 0 5 1 0
echo ""