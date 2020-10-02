#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>


TEST(Q3_Student, HandlesValue) {
    std::vector<int> vec={1,2,3,4,5};
    int n=10;
    SinglyLinkedList s(vec,n);
    
    testing::internal::CaptureStdout();
    s.print();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1 2 3 4 5 ");

    EXPECT_EQ((s.empty()), false);
    EXPECT_EQ(s.size(), 5);

    s.push_back(6);
    testing::internal::CaptureStdout();
    s.print();
    std::string output1 = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output1, "1 2 3 4 5 6 ");

    s.push_front(0);
    testing::internal::CaptureStdout();
    s.print();
    std::string output2 = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output2, "0 1 2 3 4 5 6 ");

    s.pop_back();
    testing::internal::CaptureStdout();
    s.print();
    std::string output3 = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output3, "0 1 2 3 4 5 ");

    s.pop_front();
    testing::internal::CaptureStdout();
    s.print();
    std::string output4 = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output4, "1 2 3 4 5 ");

    s.erase(s.GetIthPointer(5));
    testing::internal::CaptureStdout();
    s.print();
    std::string output5 = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output5, "1 2 3 4 ");

    s.insert_after(s.GetIthPointer(4),5);
    testing::internal::CaptureStdout();
    s.print();
    std::string output6 = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output6, "1 2 3 4 5 ");

    s.reverse();
    testing::internal::CaptureStdout();
    s.print();
    std::string output7 = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output7, "5 4 3 2 1 ");

   //Checking Tail Pointer 
   ListNode* a=s.GetBackPointer();
   EXPECT_EQ(a->val, s.tail_->val);

   //Checking Head Pointer
   ListNode* b=s.GetIthPointer(5);
   EXPECT_EQ(b->val, s.head_->val);

}