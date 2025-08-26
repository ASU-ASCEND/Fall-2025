import redis
import threading
from time import sleep

r = redis.Redis(host='localhost', port=6379, decode_responses=True)

r.set('foo', 'bar')
print(r.get('foo'))

r.hset('asdf', mapping={
  'one': 1,
  'two': 2
})

r.hset('asdf', mapping={
  'one': 3
})

def producer_thread():
  prodr = redis.Redis(host='localhost', port=6379, decode_responses=True)
  for i in range(20):
    prodr.set("val", i)
    sleep(0.1)

def consumer_thread():
  prodr = redis.Redis(host='localhost', port=6379, decode_responses=True)
  for i in range(20):
    print("Got: ", prodr.get("val"))
    sleep(.5)

producer = threading.Thread(target=producer_thread)
consumer = threading.Thread(target=consumer_thread)

producer.start()
consumer.start()

producer.join()
consumer.join()