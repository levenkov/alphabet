from conans import ConanFile, CMake

class AbcConan(ConanFile):
    generators = "cmake"

    requires = "boost/1.76.0"

    def build(self):
        cmake = self.cmake
        cmake.configure()
        cmake.build()

    @property
    def cmake(self):
        return CMake(self)
