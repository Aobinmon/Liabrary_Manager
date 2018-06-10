#include "Administrator.h"
#include "Guest.h"
#include "Book.h"
#include "Record.h"
#include "Reference.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

Book::Book(string bookName, string writerName, string press, string pressTime){
    BookName = bookName;
    WriterName = writerName;
    Press = press;
    PressTime = pressTime;
}
