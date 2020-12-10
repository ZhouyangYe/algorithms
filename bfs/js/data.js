const tree = {
  id: 'root',
  children: [
    {
      id: 'node-1',
      children: [
        {
          id: 'node-1-1',
        },
        {
          id: 'node-1-2',
          children: [
            {
              id: 'node-1-2-1',
            },
            {
              id: 'node-1-2-2',
            },
          ],
        },
        {
          id: 'node-1-3',
          children: [
            {
              id: 'node-1-3-1',
            },
            {
              id: 'node-1-3-2',
            },
          ],
        },
        {
          id: 'node-1-4',
        },
        {
          id: 'node-1-5',
          children: [
            {
              id: 'node-1-5-1',
            },
            {
              id: 'node-1-5-2',
              children: [
                {
                  id: 'node-1-5-2-1',
                },
                {
                  id: 'node-1-5-2-2',
                },
              ],
            },
          ],
        },
      ],
    },
    {
      id: 'node-2',
      children: [
        {
          id: 'node-2-1',
          children: [
            {
              id: 'node-2-1-1',
            },
            {
              id: 'node-2-1-2',
            },
          ],
        },
        {
          id: 'node-2-2',
        },
      ],
    },
    {
      id: 'node-3',
      children: [
        {
          id: 'node-3-1',
          children: [
            {
              id: 'node-3-1-1',
            },
            {
              id: 'node-3-1-2',
              children: [
                {
                  id: 'node-3-1-2-1',
                },
                {
                  id: 'node-3-1-2-2',
                },
              ],
            },
          ],
        },
        {
          id: 'node-3-2',
        },
        {
          id: 'node-3-3',
        },
      ],
    },
  ],
};

module.exports = tree;
