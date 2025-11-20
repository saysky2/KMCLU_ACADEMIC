import pandas as pd


MOST_SPECIFIC = "Ø"
MOST_GENERAL = "?"

def is_consistent(h, x):
    for hi, xi in zip(h, x):
        if hi == MOST_GENERAL:
            continue
        if hi == MOST_SPECIFIC:
            return False
        if hi != xi:
            return False
    return True


def more_general(h1, h2):
    for a, b in zip(h1, h2):
        if a == b:
            continue
        if a == MOST_GENERAL:
            continue
        return False
    return True


def minimal_generalization(h, x):
    new_h = list(h)
    for i in range(len(h)):
        if h[i] == MOST_SPECIFIC:
            new_h[i] = x[i]
        elif h[i] != x[i]:
            new_h[i] = MOST_GENERAL
    return tuple(new_h)


def minimal_specializations(h, x, domains):
    results = []
    for i in range(len(h)):
        if h[i] == MOST_GENERAL:
            for val in domains[i]:
                if val != x[i]:
                    new_h = list(h)
                    new_h[i] = val
                    results.append(tuple(new_h))
        elif h[i] != MOST_SPECIFIC and h[i] == x[i]:
            new_h = list(h)
            new_h[i] = MOST_SPECIFIC
            results.append(tuple(new_h))
    return results


def candidate_elimination(df):
    attributes = list(df.columns[:-1])
    target_col = df.columns[-1]

    df[target_col] = df[target_col].str.lower().replace({
        "positive": "yes", "true": "yes", "1": "yes",
        "negative": "no", "false": "no", "0": "no"
    })

    domains = [sorted(df[attr].unique()) for attr in attributes]

    S = {tuple([MOST_SPECIFIC] * len(attributes))}
    G = {tuple([MOST_GENERAL] * len(attributes))}

    for index, row in df.iterrows():
        x = tuple(row[attributes].tolist())
        y = row[target_col]

        print(f"\nExample {index+1}: {x} ---> {y}")
        print("Before Update:")
        print("S =", S)
        print("G =", G)

        if y == "yes":
            G = {g for g in G if is_consistent(g, x)}

            S_new = set()
            for s in S:
                if is_consistent(s, x):
                    S_new.add(s)
                else:
                    gen = minimal_generalization(s, x)
                    if any(more_general(g, gen) for g in G):
                        S_new.add(gen)
            S = S_new

            S = {s for s in S if not any((s2 != s and more_general(s2, s)) for s2 in S)}

        else:
            S = {s for s in S if not is_consistent(s, x)}

            G_new = set()
            for g in G:
                if is_consistent(g, x):
                    specs = minimal_specializations(g, x, domains)
                    for h in specs:
                        if any(more_general(h, s) for s in S):
                            G_new.add(h)
                else:
                    G_new.add(g)
            G = G_new

            G = {g for g in G if not any((g2 != g and more_general(g, g2)) for g2 in G)}

        print("After Update:")
        print("S =", S)
        print("G =", G)

    return S, G



filename = r"C:\Users\10582\Desktop\ML-Lab\Program2\a.csv"   # Please copy and paste the data set from your system  

df = pd.read_csv(filename)

print("\n==============================")
print("CANDIDATE ELIMINATION STARTED")
print("==============================")

S_final, G_final = candidate_elimination(df)

print("\n==============================")
print(" FINAL VERSION SPACE ")
print("==============================")
print("Specific Boundary (S):")
for h in S_final:
    print("  ", h)

print("\nGeneral Boundary (G):")
for h in G_final:
    print("  ", h)
