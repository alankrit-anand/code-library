void compress(vi &a)
{
	vi b = a;
	sort(all(b));
	b.resize(unique(all(b)) - b.begin());

	for(int &x : a)
	{
		x = lb(all(b), x) - b.begin();
	}
}