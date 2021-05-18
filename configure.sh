touch config.h

echo "#define GETTEXT_PACKAGE \"eu.kosy.Kerberos\"" > config.h
echo "#define PGPREFIX \"$1\"" >> config.h
echo "#define PGDATA \"$2\"" >> config.h
