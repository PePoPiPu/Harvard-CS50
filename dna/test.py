match = {"AGATC": 0, "TTTTTTCT":0, "AATG":0, "TCTAG":0, "GATA":0, "TATC":0, "GAAA":0, "TCTG":0}

match["AGATC"] = longest_match(sequence, subsequence[0])
match["TTTTTTCT"] = longest_match(sequence, subsequence[1])
match["AATG"] = longest_match(sequence, subsequence[2])
match["TCTAG"] = longest_match(sequence, subsequence[3])
match["GATA"] = longest_match(sequence, subsequence[4])
match["TATC"] = longest_match(sequence, subsequence[5])
match["GAAA"] = longest_match(sequence, subsequence[6])
match["TCTG"] = longest_match(sequence, subsequence[7])

match[subsequence[i]] = longest_match(sequence, subsequence[i])