g++ parsing_proj.cpp -o parsingtab.out
./parsingtab.out <input.in
g++ project.cpp -o project.out
./project.out $1 <parsing_table.txt 