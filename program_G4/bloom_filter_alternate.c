struct Packet {
  int sport;
  int dport;
  int member;
  int filter1_idx;
  int filter2_idx;
  int filter3_idx;
};

int filter1[256];
int filter2[256];
int filter3[256];

int hash1(int a, int b) {
  return a * b;
}

int hash2(int a, int b) {
  return a * b;
}

int hash3(int a, int b) {
  return a * b;
}

void func(struct Packet pkt) {
  pkt.filter1_idx = hash1(pkt.sport, pkt.dport) % 256;
  pkt.filter2_idx = hash2(pkt.sport, pkt.dport) % 256;
  pkt.filter3_idx = hash3(pkt.sport, pkt.dport) % 256;

  if (filter1[pkt.filter1_idx] &&
      filter2[pkt.filter2_idx] &&
      filter3[pkt.filter3_idx]) {
    pkt.member = 1;
  } else {
    filter1[pkt.filter1_idx] = 1;
    filter2[pkt.filter2_idx] = 1;
    filter3[pkt.filter3_idx] = 1;
  }
}
