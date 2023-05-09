 use questions;
 delete from questions.answer;
 delete from questions.link;
 delete from questions.question;
 
 load data local infile '~/projects/tests/base/questions.txt' into table
 questions.question;

 load data local infile '~/projects/tests/base/answers.txt' into table
 questions.answer;

 load data local infile '~/projects/tests/base/links.txt' into table
 questions.link;
