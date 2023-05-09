This small project allows you to load questions and check yourself.
It uses mysql as database (dump of database is in the project folder)
- Create new user "student"@"localhost" with password "student".
- Create empty database "questions" and get appropriate rights to user for requests.
- If necessary, change "inline_local" on both sql client/server sides.
- Load db structure by using: "**mysql -u root -p questions < questions_dump.sql**"
- Load tables from "base" folder. You can use "db_filling_script.sql" in mysql prompt.
