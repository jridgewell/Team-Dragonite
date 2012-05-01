yaml_srcdir = yaml-cpp/src
yaml_incdir = yaml-cpp/include
yaml_builddir = build
yaml_srcs = $(wildcard $(yaml_srcdir)/*.cpp)
yaml_objs = $(addprefix $(yaml_builddir)/, $(notdir $(yaml_srcs:.cpp=.o)))
CXXFLAGS += -I$(yaml_incdir)

all: $(yaml_builddir)/yaml.a
	$(CXX) $(CXXFLAGS) -o main *.cpp $^
clean:
	rm -f $(yaml_builddir)/*.o
	rm -f $(yaml_builddir)/yaml.a
	rm -f main

$(yaml_builddir)/yaml.a: $(yaml_objs)
	$(AR) $(ARFLAGS) $@ $^	
%.o : $(yaml_srcdir)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $(yaml_builddir)/$@
$(yaml_builddir)/graphbuilder.o: $(yaml_srcdir)/contrib/graphbuilder.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $(yaml_builddir)/$@
$(yaml_builddir)/graphbuilderadapter.o: $(yaml_srcdir)/contrib/graphbuilderadapter.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $(yaml_builddir)/$@
