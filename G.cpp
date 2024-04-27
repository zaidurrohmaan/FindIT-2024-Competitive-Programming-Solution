#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ld long double
#define ll long long
#define point pair<ld, ld>
#define line pair<point, point>

bool onSegment(point p, point q, point r) 
{ 
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && 
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y)) 
       return true; 
  
    return false; 
} 

int orientation(point p, point q, point r) 
{ 
    ld val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if ((int)val == 0) return 0;
	
    return (val > 0)? 1: 2;
}

bool doIntersect(point p1, point q1, point p2, point q2) 
{ 

    int o1 = orientation(p1, q1, p2); 
    int o2 = orientation(p1, q1, q2); 
    int o3 = orientation(p2, q2, p1); 
    int o4 = orientation(p2, q2, q1); 
  
    if (o1 != o2 && o3 != o4) return true; 
    if (o1 == 0 && onSegment(p1, p2, q1)) return true; 
    if (o2 == 0 && onSegment(p1, q2, q1)) return true; 
    if (o3 == 0 && onSegment(p2, p1, q2)) return true; 
    if (o4 == 0 && onSegment(p2, q1, q2)) return true; 
  
    return false;
}

ld distance(point A, point B) {
	return sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y, 2));
}

bool isIntersect(line A, line B) {
	return doIntersect(A.x, A.y, B.x, B.y);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	point S, F;
	ll N;
	cin >> S.x >> S.y >> F.x >> F.y >> N;
	vector<line> VL(N);
	vector<point> VP;
	map<point, ld> dist;
	map<point, vector<point>> adj;
	map<line, ld> W;
	for (int i = 0; i < N; i++) {
		cin >> VL[i].x.x >> VL[i].x.y >> VL[i].y.x >> VL[i].y.y;
		VP.push_back(VL[i].x);
		VP.push_back(VL[i].y);
	}
	VP.push_back(S);
	VP.push_back(F);
	ll n_points = VP.size();

	for (int i = 0; i < n_points - 1; i++) {
		for (int j = i + 1; j < n_points; j++) {
			line curLine = {VP[i], VP[j]};
			bool valid = true;
			for (line L : VL) {
				if (curLine.x != L.x &&
					curLine.y != L.y &&
					curLine.x != L.y &&
					curLine.y != L.x &&
					isIntersect (curLine, L)) {
						valid = false;
				}
				if (curLine == L) valid = false;
			}
			if (valid) {
				// cout << curLine.x.x << "," << curLine.x.y << " --- " << curLine.y.x << "," << curLine.y.y << "\n";
				adj[curLine.x].push_back(curLine.y);
				adj[curLine.y].push_back(curLine.x);
				dist[curLine.x] = LLONG_MAX;
				dist[curLine.y] = LLONG_MAX;
				ld d = distance(curLine.x, curLine.y);
				W[{curLine.x, curLine.y}] = d;
				W[{curLine.y, curLine.x}] = d;
			}
		}
	}

	queue<point> Q;
	Q.push(S);
	dist[S] = 0LL;
	while(!Q.empty()) {
		point cur = Q.front();
		Q.pop();
		for (point P: adj[cur]) {
			if (dist[P] > dist[cur] + W[{cur, P}]) {
				dist[P] = dist[cur] + W[{cur, P}];
				Q.push(P);
			}
		}
	}

	// for (point p: VP) {cout << p.x << "," << p.y << " -> " << dist[p] << "\n";}
	cout << dist[F];
}
