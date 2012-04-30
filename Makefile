yaml_srcdir = yaml-cpp/src
yaml_incdir = yaml-cpp/include
yaml_builddir = build
OBJS=aliasmanager.o emitfromevents.o exp.o nodeownership.o regex.o \
	scantoken.o tag.o binary.o emitter.o iterator.o null.o scanner.o \
	simplekey.o conversion.o emitterstate.o node.o ostream.o scanscalar.o \
	singledocparser.o directives.o emitterutils.o nodebuilder.o parser.o \
	scantag.o stream.o graphbuilder.o graphbuilderadapter.o
CCFLAGS += -I$(yaml_incdir)

all: $(OBJS)
	g++ $(CCFLAGS) -o main *.cpp $(wildcard $(yaml_builddir)/*.o)
clean:
	rm -f $(yaml_builddir)/*.o	
	rm -f main

%.o : $(yaml_srcdir)/%.cpp
	g++ $(CCFLAGS) -c $< -o $(yaml_builddir)/$@
graphbuilder.o: $(yaml_srcdir)/contrib/graphbuilder.cpp
	g++ $(CCFLAGS) -c $< -o $(yaml_builddir)/$@
graphbuilderadapter.o: $(yaml_srcdir)/contrib/graphbuilderadapter.cpp
	g++ $(CCFLAGS) -c $< -o $(yaml_builddir)/$@
