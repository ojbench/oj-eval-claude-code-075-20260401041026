#!/usr/bin/env python3
# Direct code submission helper for ACMOJ
import requests
import json
import os
import sys

def submit_code(problem_id, code_file, language='cpp'):
    access_token = os.environ.get('ACMOJ_TOKEN')
    if not access_token:
        print("Error: ACMOJ_TOKEN not set")
        sys.exit(1)

    api_base = 'https://acm.sjtu.edu.cn/OnlineJudge/api/v1'
    headers = {
        'Authorization': f'Bearer {access_token}',
        'Content-Type': 'application/x-www-form-urlencoded',
        'User-Agent': 'ACMOJ-Python-Client/2.2'
    }

    # Read the code file
    with open(code_file, 'r') as f:
        code_content = f.read()

    # Submit with specified language
    data = {
        'language': language,
        'code': code_content
    }

    url = f'{api_base}/problem/{problem_id}/submit'
    response = requests.post(url, headers=headers, data=data, timeout=10)
    result = response.json()
    print(f"Submission ID: {result.get('id')}")
    return result

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("Usage: python3 submit_code.py <problem_id> <code_file> [language]")
        sys.exit(1)

    problem_id = int(sys.argv[1])
    code_file = sys.argv[2]
    language = sys.argv[3] if len(sys.argv) > 3 else 'cpp'

    submit_code(problem_id, code_file, language)
