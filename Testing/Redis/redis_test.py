import redis
import threading
from time import sleep, time

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

stream_key = "valley"
r.xadd(stream_key, {'ts': time(), 'v': 0})

v = int(r.xrevrange(name=stream_key, count=1)[0][1]['v'])
print("Got:", v)
v += 1
r.xadd(stream_key, {'ts': time(), 'v': v})

v = int(r.xrevrange(name=stream_key, count=1)[0][1]['v'])
print("Got:", v)

# def producer_thread():
#   prodr = redis.Redis(host='localhost', port=6379, decode_responses=True)
#   for i in range(20):
#     prodr.xadd(stream_key, {'ts': time(), 'v': i})
#     sleep(1)

# def consumer_thread():
#   prodr = redis.Redis(host='localhost', port=6379, decode_responses=True)
#   for i in range(20):
#     # print("Got: ", prodr.xread(
#     #   count=1, 
#     #   streams={stream_key:'$'},
#     #   block=0
#     # ))
#     print("Got:", prodr.xrevrange(name=stream_key, count=1))
#     sleep(.5)

# producer = threading.Thread(target=producer_thread)
# consumer = threading.Thread(target=consumer_thread)

# producer.start()
# consumer.start()

# producer.join()
# consumer.join()