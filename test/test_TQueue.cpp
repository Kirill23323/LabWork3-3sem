#include "TQueue.h"
#include <gtest.h>

TEST(TQueue, queue_is_full)
{
  TQueue <int> queue(3);
  queue.Push(1);
  queue.Push(2);
  queue.Push(3);
  EXPECT_EQ(true, queue.IsFull());
}

TEST(TQueue, queue_is_empty)
{
  TQueue <int> q(1);
  q.Push(1);
  q.Pop();
  EXPECT_EQ(true, q.IsEmpty());
}

TEST(TQueue, managed_to_get_the_start_element)
{
  TQueue <int> q(4);
  q.Push(1);
  q.Push(2);
  q.Push(3);
  q.Push(4);
  EXPECT_EQ(1, q.StartElem());
}

TEST(TQueue, return_correct_size)
{
  TQueue <int> q(4);
  q.Push(1);
  q.Push(2);
  q.Push(3);
  q.Push(4);
  q.Pop();
  EXPECT_EQ(3, q.Size());
}

TEST(TQueue, you_cannot_extract_a_value_from_an_empty_queue)
{
  TQueue <int> q(1);
  q.Push(1);
  q.Pop();
  ASSERT_ANY_THROW(q.Pop());
}

TEST(TQueue, you_cannot_take_the_start_element_from_an_empty_queue)
{
  TQueue <int> q(1);
  q.Push(1);
  q.Pop();
  ASSERT_ANY_THROW(q.StartElem());
}

TEST(TQueue, the_pop_function_returns_the_correct_value)
{
  TQueue <int> q(4);
  q.Push(1);
  q.Push(2);
  q.Push(3);
  q.Push(4);
  EXPECT_EQ(1, q.Pop());
}

TEST(TQueue, copy_constructor_test)
{
  TQueue <int> q(4);
  q.Push(10);
  q.Push(20);
  q.Push(30);
  q.Push(40);
  TQueue <int> q2(q);
  q2.Pop();
  EXPECT_EQ(20, q2.Pop());

}