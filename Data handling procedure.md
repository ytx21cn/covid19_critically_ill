# Data handling procedure

## Preprocessing
1. Copy the "**imputation.csv**" file from the "models" directory to the "base" directory, and rename it as "**input.csv**".
2. Modify the code in "preprocess.py" for reading CSV, to read data in the correct format:
    ```
    df = pd.read_csv(fname_input, names=['patient_ID', *FEATURE_LIST])
    ```
3. Use `python3.6 preprocess.py input.csv` to preprocess data. The generated data is at "**input.csv_processed.csv**".
