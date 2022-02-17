import sqlite3
from sqlite3 import Error
def sql_crud():
    try:
        connects=sqlite3.connect('pro.db')
        return connects
    except Error:
        print(Error)
def sql_operations(connects):
    cursorObject = connects.cursor()
    cursorObject.execute("CREATE TABLE fruits(fruit_name char(50),fruit_cost n(5))")
    cursorObject.executescript("""
    INSERT INTO fruits VALUES('Apple', 200);
    INSERT INTO fruits VALUES('Mango', 180);
    INSERT INTO fruits VALUES('Grapes', 250);
    INSERT INTO fruits VALUES('Banana',520 );
    INSERT INTO fruits VALUES('Kiwi', 120);
    """)
    connects.commit()
    cursorObject.execute("SELECT * FROM fruits")
    rows=cursorObject.fetchall()
    print("product details")
    for row in rows:
        print(row)
    print("Update fruit_cost 180 to 360 where fruit_name is Mango")
    sql_update_query = """UPDATE fruits SET fruit_cost = 360 WHERE fruit_name = 'Mango'"""
    cursorObject.execute(sql_update_query)
    connects.commit()
    print("Record Updated successfully ")
    cursorObject.execute("SELECT * FROM fruits")
    rows = cursorObject.fetchall()
    print("After updating Fruits details:")
    for row in rows:
        print(row)
    print("Dlete fruit where name is 'Banana':")
    sql_delete_query = """DELETE FROM fruits WHERE fruit_cost = 520"""
    cursorObject.execute(sql_delete_query)
    connects.commit()
    print("Record Deleted successfully ")
    cursorObject.execute("SELECT * FROM fruits")
    rows = cursorObject.fetchall()
    print("After deleting product details:")
    for row in rows:
      print(row)
sqllite_conn = sql_crud()
sql_operations(sqllite_conn)
if (sqllite_conn):
    sqllite_conn.close()
    print("The SQLite connection is closed.")
