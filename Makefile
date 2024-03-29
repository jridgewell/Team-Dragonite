yaml_srcdir = yaml-cpp/src
yaml_incdir = yaml-cpp/include
yaml_builddir = yaml-cpp/build
yaml_srcs = $(wildcard $(yaml_srcdir)/*.cpp)
yaml_objs = $(addprefix $(yaml_builddir)/, $(notdir $(yaml_srcs:.cpp=.o)))
build_dir = build
srcs = $(wildcard *.cpp) $(wildcard utils/*.cpp)
objs = $(addprefix $(build_dir)/, $(notdir $(srcs:.cpp=.o)))
CXXFLAGS += -I$(yaml_incdir)

all: $(yaml_builddir)/yaml.a
	$(CXX) $(CXXFLAGS) -o main *.cpp utils/*.cpp $^
debug: $(yaml_builddir)/yaml.a  $(objs)
	$(CXX) $(CXXFLAGS) -g -ansi -Wall -Wunused -Wextra -Wswitch -Wshadow -Wmissing-braces -Wreturn-type -Wparentheses -Wmissing-field-initializers -Wsign-compare -Wmissing-prototypes -o main $^
clean:
	rm -f $(build_dir)/*.o
	rm -f $(yaml_builddir)/*.o
	rm -f $(yaml_builddir)/yaml.a
	rm -f main

$(build_dir)/%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
$(build_dir)/File.o : utils/File.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
$(build_dir)/Input.o : utils/Input.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(yaml_builddir)/yaml.a: $(yaml_objs)
	$(AR) $(ARFLAGS) $@ $^
$(yaml_builddir)/%.o : $(yaml_srcdir)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
$(yaml_builddir)/graphbuilder.o: $(yaml_srcdir)/contrib/graphbuilder.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
$(yaml_builddir)/graphbuilderadapter.o: $(yaml_srcdir)/contrib/graphbuilderadapter.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
