#include "gtest\gtest.h"
#include "Calculation.h"
#include "PolishRecord.h"
#include "Queue.h"
#include "Stack.h"
#include <string> 

using namespace std;
////////////////////////////////////////ÒÅÑÒÛ ÊÀËüÊÓËßÒÎÐÀ//////////////////////////////////


TEST(MyCalcTests, testCaculation)
{

	EXPECT_EQ(5,calculation(PolishRecord("2+3")));
	EXPECT_EQ(3,calculation(PolishRecord("10-22/11-5")));
	EXPECT_EQ(-26,calculation(PolishRecord("2+3-10*4+99/11")));
}

TEST(MyCalcTests, testsbracket)
{
	ASSERT_TRUE(right("(2+3)"));
	ASSERT_TRUE(right("2+3"));
	ASSERT_TRUE(right("(2+3)*(10+2)"));
	
}


////////////////////////////////////ÒÅÑÒÛ ÑÒÅÊÀ///////////////////////////////////////////////

TEST(MyStackChar, testsStackPush_and_ControlMemory)
{
	Stack temp(2);
	ASSERT_TRUE(temp.isEmpty());
	ASSERT_FALSE(temp.isFull());
	temp.push('a');
	ASSERT_FALSE(temp.isEmpty());
	ASSERT_FALSE(temp.isFull());
	temp.push('1');
	ASSERT_FALSE(temp.isEmpty());
	ASSERT_TRUE(temp.isFull());

}


TEST(MyStackChar, testsStackpop)
{
	Stack temp(2);
	temp.push('a');
	temp.push('1');
	EXPECT_EQ('1',temp.pop());
	EXPECT_EQ('a',temp.pop());

}

TEST(MyStackChar, tests_getCount)
{
	Stack temp(2);
	EXPECT_EQ(0,temp.getCount());
	temp.push('a');
	EXPECT_EQ(1,temp.getCount());
	temp.push('1');
	EXPECT_EQ(2,temp.getCount());
	EXPECT_EQ('1',temp.pop());
	EXPECT_EQ(1,temp.getCount());
	EXPECT_EQ('a',temp.pop());
	EXPECT_EQ(0,temp.getCount());
}


TEST(MyStackChar, tests_critical_situations)
{
	Stack temp(2);
	ASSERT_ANY_THROW(temp.pop());
	temp.push('a');
	temp.push('a');
	ASSERT_ANY_THROW(temp.push('a'));
}


TEST(MyStacFloat, testsStackPush_and_ControlMemory)
{
	floatStack temp(2);
	ASSERT_TRUE(temp.isEmpty());
	ASSERT_FALSE(temp.isFull());
	temp.push(1);
	ASSERT_FALSE(temp.isEmpty());
	ASSERT_FALSE(temp.isFull());
	temp.push(2);
	ASSERT_FALSE(temp.isEmpty());
	ASSERT_TRUE(temp.isFull());

}


 TEST(MyStackFloat, testsStackpop)
{
	floatStack temp(2);
	temp.push(2);
	temp.push(10);
	EXPECT_EQ(10,temp.pop());
	EXPECT_EQ(2,temp.pop());

}

TEST(MyStackFloat, tests_getCount)
{
	floatStack temp(2);
	EXPECT_EQ(0,temp.getCount());
	temp.push(3);
	EXPECT_EQ(1,temp.getCount());
	temp.push(22);
	EXPECT_EQ(2,temp.getCount());
	EXPECT_EQ(22,temp.pop());
	EXPECT_EQ(1,temp.getCount());
	EXPECT_EQ(3,temp.pop());
	EXPECT_EQ(0,temp.getCount());
} 

TEST(MyStackFloat, tests_critical_situations)
{
	floatStack temp(2);
	ASSERT_ANY_THROW(temp.pop());
	temp.push(1);
	temp.push(1);
	ASSERT_ANY_THROW(temp.push(1));
}


/////////////////////////////////////ÒÅÑÒÛ Î×ÅÐÅÄÈ//////////////////////////////////////////

TEST(MyQueue, testsQueuePush_and_ControlMemory)
{
	Queue temp(3);
	ASSERT_TRUE(temp.isEmpty());
	ASSERT_FALSE(temp.isFull());
	temp.push("a");
	ASSERT_FALSE(temp.isEmpty());
	ASSERT_FALSE(temp.isFull());
	temp.push("1");
	ASSERT_FALSE(temp.isEmpty());
	ASSERT_TRUE(temp.isFull()); 

}

TEST(MyQueue, testsQueuepop)
{
	Queue temp(3);
	temp.push("a");
	temp.push("1a1");
	EXPECT_EQ("a",temp.pop());
	EXPECT_EQ("1a1",temp.pop());

}

TEST(MyQueue, tests_getSize)
{
	Queue temp(2);
	Queue temp1(1);
	Queue temp2(2);
	Queue temp3(3);
	EXPECT_EQ(1,temp1.getsize());
	EXPECT_EQ(2,temp2.getsize());
	EXPECT_EQ(3,temp3.getsize());
	EXPECT_EQ(temp.getsize(), temp2.getsize());
	EXPECT_NE(temp.getsize(), temp1.getsize());
	EXPECT_NE(temp.getsize(), temp3.getsize());
	EXPECT_NE(temp1.getsize(), temp3.getsize());	
}


TEST(MyQueue, tests_critical_situations)
{
	Queue temp(2);
	ASSERT_ANY_THROW(temp.pop());
	temp.push("aaa");
	ASSERT_ANY_THROW(temp.push("111"));
}



///////////////////////////////ÒÅÑÒÛ ÏÎËÜÑÊÎÉ ÇÀÏÈÑÈ///////////////////////////////

TEST(MyPolishRecord, tests_polishRecord)
{
	std::string str; 
	str = "";
	Queue *temp;
	temp = PolishRecord("2+3");
	str += temp->pop();
	str += temp->pop();
	str += temp->pop();
	EXPECT_EQ("23+", str);
}