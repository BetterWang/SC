def partition(collection):
    if len(collection) == 1:
        yield [ collection ]
        return
    first = collection[0]
    for smaller in partition(collection[1:]):
        # insert `first` in each of the subpartition's subsets
        for n, subset in enumerate(smaller):
            yield smaller[:n] + [[ first ] + subset]  + smaller[n+1:]
        # put `first` in its own subset 
        yield [ [ first ] ] + smaller

def countpn(item):
    y = {'+':0, '-':0}
    for x in item:
        y[x] += 1
    return y


something = list(range(8))
harm = '++++----'

part = list(partition(something))

for n, p in enumerate(part, 1):
    print(n, len(p), sorted(p))

print('=================')
print( ' len(part) = ', len(part) ) 
print('=================')


vd = {}
part.sort( key = lambda x: len(x) )
for p in part:
    #print(p)
    x = []
    p.sort( key = lambda x: len(x) )
    for p0 in p:
        ha  = [ harm[i] for i in p0 ]
        x.append(''.join(ha))
    y = '_'.join(x)
    print( x )
    if y in vd:
        vd[y] += 1.
    else:
        vd[y] = 1.
print(vd)
for k, v in vd.items():
    #print( k, v )
    term = []
    for item in k.split('_'):
        cnt = countpn(item)
        prefix = '%s'
        if cnt['+'] < cnt['-']:
            prefix = 'std::conj(%s)'
            a = cnt['+']
            cnt['+'] = cnt['-']
            cnt['-'] = a
        term.append( prefix % ('Qc'+str(cnt['+']) + '_' + str(cnt['-'])) )
        #print( item, cnt )
    terms = ' * '.join(term)
    terms = '-%s * '%v + terms
    print( terms )


