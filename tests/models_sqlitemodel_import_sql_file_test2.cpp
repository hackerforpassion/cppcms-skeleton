#include <iostream>

#include "models/SqliteModel.h" 
#include "test.h"

#define OK "[OK]"
#define FAIL "[FAILED]"

#define SQL_PATH "../tests/" 
#define TEST_NAME "models_sqlitemodel_import_sql_file_test"
#define BUG_INSERT_SQL "bug_insert.sql"
#define BUG_INSERT_CREATE_TABLES_SQL "bug_insert_create_tables.sql"
int main() {

    // the goal here is to test the following case
    // 
    // an import containing INSERT fails with a unique constraint
    // errors though the table is empty and the import works 
    // when done directly (i.e using  sqlite3 my.db < the_file.sql
    bool nothingFailed = true;

    cppcmsskel::models::SqliteModel model("test2.db");

    // we first create the database
    CPPCMSSKEL_TEST_RESULT_WORK(
        "Try to create the tables ... " ,
        model.import_sql_file(
          SQL_PATH BUG_INSERT_CREATE_TABLES_SQL
        ),
        nothingFailed
    );

    // and we load the data
    CPPCMSSKEL_TEST_RESULT_WORK(
        "Now we inset some data",
        model.import_sql_file(
          SQL_PATH BUG_INSERT_SQL
        ),
        nothingFailed
    );


    if (nothingFailed) {
        return 0;
    } else {
        return 1;
    }
}
