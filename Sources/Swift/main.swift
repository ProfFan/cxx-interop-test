import CXX
import std.vector
import std.string

func runExpr() {

    var v: V = V()
    var vec : cxx_std_vector_of_int = v.getVec().pointee

    /// Note that vec here is a pointer to a vector object!!!
    /// If we access elements with vec[2] there will be a memory leak due to a copy
    let vector_view = UnsafeMutableBufferPointer(start: vec.data(), count: vec.size())

    print("size = \(vec.size())") // , type = \(type(of: vec[0]))")
    print("std::vector: ", terminator: "[ ")
    for i in 0..<vec.size() {
        // print(vec[i], terminator: " ") // THIS WILL LEAK
        print(vector_view[i], terminator: " ")
    }
    print("]\n")

    print("Now we push some values into the vector.")

    var a: Int32 = 100
    vec.push_back(&a)
    a = 101
    vec.push_back(&a)

    let dump = String(cString: test.Dumper.dump(&vec).c_str()!)

    print("Dumped string: \(dump)")
}

runExpr()

print("Done.")
