#define FREEZE_TIME 10
#define DELTA1 1
#define DELTA2 2
#define QMAX 5

struct Packet {
  int loss;
  int qlen;
  int now;
  int link_idle;
  int cond1;
  int now_plus_free;
};

int last_update;
int p_mark;

void func(struct Packet p) {
    p.now_plus_free = p.now - FREEZE_TIME;
    p.qlen = p.now + DELTA1;
    p.cond1 = p.now + QMAX;
    if (p.now_plus_free > last_update)
        if (p.len>=1)
                if (p.cond1>=5)
                        if (p.loss>=0){
      p_mark = p_mark - DELTA2;
      last_update = p.now;
    }
}

