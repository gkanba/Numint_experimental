#ifdef __IG_INTEGRATE_H_
#define __IG_INTEGRATE_H_

class Integrate {
public:
      Integrate();
      Integrate(Integrate &&) = default;
      Integrate(const Integrate &) = default;
      Integrate &operator=(Integrate &&) = default;
      Integrate &operator=(const Integrate &) = default;
      ~Integrate();

private:
      
};

Integrate::Integrate() {
}

Integrate::~Integrate() {
}

#endif
