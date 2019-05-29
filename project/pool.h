#ifndef POOL_H
#define POOL_H

#include <vector>

template <typename T>
class Pool
{
    private:
        struct PoolRecord
        {
            T* instance;
            bool in_use;
        };

        std::vector<PoolRecord> m_pool;

    public:
        T* createNewObject()
        {
            for (int i = 0; i < m_pool.size(); ++i)
            {
                if (! m_pool[i].in_use)
                {
                    m_pool[i].in_use = true; // переводим объект в список используемых
                    return m_pool[i].instance;
                }
            }
            // если не нашли свободный объект, то расширяем пул
            PoolRecord record;
            record.instance = new T;
            record.in_use   = true;

            m_pool.push_back(record);

            return record.instance;
        }

        void deleteObject(T* object)
        {
            // в реальности не удаляем, а лишь помечаем, что объкт свободен
            for (int i = 0; i < m_pool.size(); ++i)
            {
                if (m_pool[i].instance == object)
                {
                    m_pool[i].in_use = false;
                    break;
                }
            }
        }

        virtual ~Pool()
        {
            // теперь уже "по-настоящему" удаляем объекты
            for (int i = 0; i < m_pool.size(); ++i)
                delete m_pool[i].instance;
        }
};


#endif // POOL_H
