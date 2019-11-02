//
// Created by Daolin on 2019/10/28.
//
#include <fstream>
#include <string>
#include <cassert>

using namespace std;

/// 获取name所在的位置和它包含数据的大小
pair<int, int> find_subchunk(ifstream& in, const string& name){
    in.seekg(12);

    while(true) {
        char c[5];
        in.read(c, 4);
        c[4] = '\0';
        string chunk_name(c);

        /// 从二进制文件中 read 数字等类型时时要这么read
        int size;
        in.read((char *) &size, sizeof(int));

        if (name == chunk_name)
            return {in.tellg(), size};

        in.seekg(size, ios::cur);
    }
}

void decreaseVolume() {
    ifstream in("C:\\Users\\46611\\CLionProjects\\homework\\test.wav", ios::binary);
    ofstream out("C:\\Users\\46611\\CLionProjects\\homework\\test_copy.wav", ios::binary);
    assert(!in.fail() && !out.fail());

    in.unsetf(ios::skipws);

    auto combo = find_subchunk(in, "data");
    int offset = combo.first;
    int size = combo.second;

    in.seekg(0);

    char c;
    for(int i = 0; i < offset; i++) {
        in >> c;
        out << c;
    }

    /// 由于wav的data是short存储的, 所以我们这里要改为用short接收
    short data;
    for(int i = offset; i < offset+size; i++){
        in.read((char *)(&data), sizeof(data));
        data /= 16;
        out.write((char *)(&data), sizeof(data));
    }

}