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
#include "xthread_pool.h"
#include "gtest/gtest.h"
using namespace std;

 
//namespace {

// The fixture for testing class Foo.
class XThreadPoolTest : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if their bodies would
  // be empty.

  XThreadPoolTest() {
     // You can do set-up work for each test here.
  }

  ~XThreadPoolTest() override {
     // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:
  void SetUp() override {
     // Code here will be called immediately after the constructor (right
     // before each test).
     cout<<"SetUp XThreadPoolTest"<<endl;
  }

  void TearDown() override {
     // Code here will be called immediately after each test (right
     // before the destructor).
     cout<<"TearDown XThreadPoolTest"<<endl;
  }
  // Class members declared here can be used by all tests in the test suite
  // for Foo.
};

// Tests that the Foo::Bar() method does Abc. ����
TEST_F(XThreadPoolTest, Init) {
  EXPECT_EQ(7 * 6, 42);
}

int main(int argc,char *argv[])
{
    cout<<"test xthread"<<endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
