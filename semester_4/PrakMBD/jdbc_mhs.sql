use jdbc_mhs;

create table mahasiswa (
	id int(11) primary key auto_increment not null,
    nama varchar(20) not null
);

create user 'mahasiswa'@'localhost' identified by 'rahasia';
grant all privileges on jbdc_mhs.* to 'mahasiswa'@'localhost';
flush privileges;
