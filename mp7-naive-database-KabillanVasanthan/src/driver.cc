#include <iostream>

#include "db.hpp"
#include "db_table.hpp"

int main() {
  DbTable table;
  
  table.AddColumn(std::make_pair("Name", DataType::kString));
  table.AddRow({"kabillan"});
  table.AddColumn(std::make_pair("GPA", DataType::kDouble));
  
  table.AddColumn(std::make_pair("Gender", DataType::kString));
  table.AddRow({"kabillan","4.0","gay"});
  table.AddColumn(std::make_pair("age", DataType::kInt));
  table.AddRow({"josh","3.0","gay", "17"});
  table.AddRow({"abby","3.3","male", "23"});
  table.DeleteRowById(3);

  DbTable copy;
  copy.AddColumn(std::make_pair("Name", DataType::kString));
  copy.AddRow({"tom"});
  //copy = table;

  Database base;


  std::cout << table;
}