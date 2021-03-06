#pragma once
namespace itertools
{
    template <typename T1, typename T2>
    class product 
    {
        private:
        T1 itr1;
        T2 itr2;
        
        public:
        product(T1 a, T2 b) : itr1(a), itr2(b) {

        }
        
        template <typename P1, typename P2>
        class iterator
        {
          private:
            P1 i1;
            P2 i2;

            public:
            iterator(P1 p1, P2 p2) : i1(p1), i2(p2) {

            }

            std::pair<decltype(*i1),decltype(*i2)> operator*() const {

             return  std::pair<decltype(*i1),decltype(*i2)> (*i1 , *i2);
}

            iterator<P1, P2>& operator++() {

			    return *this;
            }

		    bool operator==(iterator<P1,P2> it) const {
			    return false;
		    }

		    bool operator!=(iterator<P1,P2> it) const {
			    return false;
            }
        };

        public:

        auto begin()
        {
            return iterator <decltype(itr1.begin()),decltype(itr2.begin())> (itr1.begin(), itr2.begin());;
        }

        auto end()
        {
            return iterator <decltype(itr1.end()),decltype(itr2.end())> (itr1.end(), itr2.end());;
        }

    };
}