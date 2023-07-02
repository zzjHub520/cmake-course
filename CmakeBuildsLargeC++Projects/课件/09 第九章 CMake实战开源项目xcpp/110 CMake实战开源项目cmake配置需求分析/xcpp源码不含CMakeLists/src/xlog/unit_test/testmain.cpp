//////////////////////////////////  @��Ȩ˵��  //////////////////////////////////////////////////
///						Jiedi(China nanjing)Ltd.                                    
/// @��Ȩ˵�� ����Ϳγ̰�Ȩ���Ĳܿ���ӵ�в��Ѿ���������Ȩ���˴��������Ϊѧϰ�ο���������Ŀ��ʹ�ã�
/// �γ����漰����������Դ���������������Ӧ����Ȩ
/// �γ�Դ�벻����ֱ��ת�ص������Ĳ��ͣ�������������ƽ̨�������������������߿γ̡�
/// �γ����漰����������Դ���������������Ӧ����Ȩ  @@              
/////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////  Դ��˵��  //////////////////////////////////////////////////
/// ��Ŀ����: CMake��������c++��Ŀ
/// ����   : 			    http://blog.csdn.net/jiedichina
/// ��Ѷ����			    https://jiedi.ke.qq.com/
/// ѧ��				    ���� �Ĳܿ�
/// ���Ŀ���			    http://cppds.com 
/// CMake�ֲ�    	        http://cmake.org.cn
/// �����������γ�qqȺ ��296249312����ͬѧ���� 
/// ��ӭ���Ĳܿ���ʦ��΢�ţ�cppxcj
///�������Ŀ���Ⱥ��296249312��ֱ����ϵȺ��ͷ����ؿγ�����
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// �γ̽���qqȺ296249312 //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////// COMMENT ///////////////////////////////////////////////

#include <iostream>
#include "xlog.h"
#include "gtest/gtest.h"
#include <fstream>
#include <cstdio>
using namespace std;
using namespace xcpp;
#define TESTLOG "testlog.txt"
class XLogTest : public ::testing::Test {
 protected:
  XLogTest() {

  }

  ~XLogTest() override {
  }

  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
     cout<<"SetUp"<<endl;
     std::remove(TESTLOG);
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
     cout<<"TearDown"<<endl;
  }
  // Class members declared here can be used by all tests in the test suite
  // for Foo.
};
TEST_F(XLogTest, InitXLog) {
    auto re = xcpp::InitXLog("MyApp","./", TESTLOG);
    ASSERT_TRUE(re);
    xcpp::CloseXLog();
    ifstream ifs(TESTLOG);
    ASSERT_TRUE(ifs);
    if(ifs)ifs.close();
    std::remove(TESTLOG);
    //Fatal assertion	Nonfatal assertion
    //ASSERT_TRUE(condition);	EXPECT_TRUE(condition);
}

TEST_F(XLogTest, WriteLog) {
    auto re = xcpp::InitXLog("MyApp", "./", TESTLOG);
    ASSERT_TRUE(re);
    xcpp::CloseXLog();
    ifstream ifs(TESTLOG);
    ASSERT_TRUE(ifs);
    if (ifs)ifs.close();
    std::remove(TESTLOG);
    //Fatal assertion	Nonfatal assertion
    //ASSERT_TRUE(condition);	EXPECT_TRUE(condition);
}

int main(int argc,char *argv[])
{
#ifdef XCPP_EXPORTS
    cout << " has XCPP_EXPORTS" << endl;
#else
    cout << " no XCPP_EXPORTS" << endl;
#endif
#ifdef XCPP_STATIC
    cout << " has XCPP_STATIC" << endl;
#else
    cout << " no XCPP_STATIC" << endl;
#endif
    
    //bool re = InitXLog("MyApp", "./", "test.ini");
    ////ASSERT_TRUE(re);
    //xcpp::CloseXLog();
    ////ifstream ifs(TESTLOG);
    ////ASSERT_TRUE(ifs);
    ////std::remove(TESTLOG);
    //int x;
    //cin >> x;
    //cout<<"test xlog"<<endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
