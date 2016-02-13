#
#Universidade Federal do Rio de Janeiro
#Escola Politecnica
#Departamento de Eletronica e de Computacao
#Prof. Marcelo Luiz Drumond Lanza
#EEL 270 - Computacao II - Turma 2015/2
 
#$Author$
#$Date$
#$Log$


CC = gcc
LD = gcc

CFLAGS = -Wall
LFLAGS = -Wall

GUCGIMAINOBJS = guCgiMain.o guUserInterface.o guFunctions.o
GUCGISHOWWEBHELPOBJS = guCgiShowWebHelp.o guUserInterface.o guFunctions.o
GUCGISHOWLICENSEOBJS = guCgiShowLicense.o guUserInterface.o guFunctions.o
GUCGISHOWREQUESTREGOBJS = guCgiShowRequestRegistrationForm.c guUserInterface.o guFunctions.o
GUCGISHOWREQUESTPWOBJS = guCgiShowRequestPasswordReset.c guUserInterface.o guFunctions.o
GUOBJS = gu.o guFunctions.o

EXECS = guMain.cgi\
        guShowLicense.cgi\
        guShowWebHelp.cgi\
	guShowRequestRegistrationForm.cgi\
	guShowRequestPasswordReset.cgi\
	gu\

#Regra Implicita
.c.o: 
	$(CC) $(CFLAGS) -c $<

guMain.cgi:  $(GUCGIMAINOBJS)
	$(LD) $(LFLAGS) -o $@ $(GUCGIMAINOBJS) ./Libraries/libmlcgi.a.FreeBSD.7.x

guShowLicense.cgi:  $(GUCGISHOWLICENSEOBJS)
	$(LD) $(LFLAGS) -o $@ $(GUCGISHOWLICENSEOBJS) ./Libraries/libmlcgi.a.FreeBSD.7.x

guShowWebHelp.cgi:  $(GUCGISHOWWEBHELPOBJS)
	$(LD) $(LFLAGS) -o $@ $(GUCGISHOWWEBHELPOBJS) ./Libraries/libmlcgi.a.FreeBSD.7.x

guShowRequestRegistrationForm.cgi:  $(GUCGISHOWREQUESTREGOBJS)
	$(LD) $(LFLAGS) -o $@ $(GUCGISHOWREQUESTREGOBJS) ./Libraries/libmlcgi.a.FreeBSD.7.x

guShowRequestPasswordReset.cgi:  $(GUCGISHOWREQUESTPWOBJS)
	$(LD) $(LFLAGS) -o $@ $(GUCGISHOWREQUESTPWOBJS) ./Libraries/libmlcgi.a.FreeBSD.7.x

gu:  $(GUOBJS)	
	$(LD) $(LFLAGS) -o $@ $(GUOBJS)

install: $(EXECS)
	mkdir -p ../../Data
	mkdir -p ../../Binaries
	mkdir -p ../../Data/Cookies
	mkdir -p /users/carlos.oliveira/public/html/GU
	mkdir -p /users/carlos.oliveira/public/html/GU/CGIs
	cp gu ../../Binaries
	cp guMain.cgi /users/carlos.oliveira/public/html/GU/CGIs	
	cp guShowLicense.cgi /users/carlos.oliveira/public/html/GU/CGIs
	cp guShowWebHelp.cgi /users/carlos.oliveira/public/html/GU/CGIs
	cp guShowRequestRegistrationForm.cgi /users/carlos.oliveira/public/html/GU/CGIs
	cp guShowRequestPasswordReset.cgi /users/carlos.oliveira/public/html/GU/CGIs	
	cp license_en-us.txt /users/carlos.oliveira/public/html/GU/CGIs	
	cp ../HTML/index_en-us.html /users/carlos.oliveira/public/html/GU
	cp ../HTML/index_pt-br.html /users/carlos.oliveira/public/html/GU
	rm -rf *.o $(EXECS)
	
clean:
	rm -rf *.o $(EXECS)

#$RCSfile$