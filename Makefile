OBJS=aliasmanager.o emitfromevents.o exp.o nodeownership.o regex.o \
	scantoken.o tag.o binary.o emitter.o iterator.o null.o scanner.o \
	simplekey.o conversion.o emitterstate.o node.o ostream.o scanscalar.o \
	singledocparser.o directives.o emitterutils.o nodebuilder.o parser.o \
	scantag.o stream.o graphbuilder.o graphbuilderadapter.o
yaml_srcdir = yaml-cpp_src
yaml_incdir = yaml-cpp_include
yaml_builddir = yaml-cpp_build

all: $(OBJS)
	g++ -I $(yaml_incdir) -o main *.cpp $(wildcard $(yaml_builddir)/*.o)
clean:
	rm -f $(yaml_builddir)/*.o	
	rm -f main

%.o : $(yaml_srcdir)/%.cpp
	g++ $(CCFLAGS) -c $< -o $(yaml_builddir)/$@
graphbuilder.o: $(yaml_srcdir)/contrib/graphbuilder.cpp
	g++ $(CCFLAGS) -c $< -o $(yaml_builddir)/$@
graphbuilderadapter.o: $(yaml_srcdir)/contrib/graphbuilderadapter.cpp
	g++ $(CCFLAGS) -c $< -o $(yaml_builddir)/$@